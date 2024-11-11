import bisect
s=input()
n=len(s)
if n!=26:
  alp=[1]*26
  for i in s:
    alp[ord(i)-ord('a')]=0
  for i in range(26):
    if alp[i]:break
  ans=s+chr(ord('a')+i)
else:
  alp=[]
  for i in range(n-1,-1,-1):
    if bisect.bisect_left(alp,ord(s[i]))==len(alp):
      bisect.insort_left(alp,ord(s[i]))
    else:
      ans=s[:i]+chr(alp[bisect.bisect_left(alp,ord(s[i]))])
      break
  else:ans=-1
print(ans)