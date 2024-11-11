S = input()
N = len(S)
 
l, r = 0, N-1
res = ""
mid = ""
while l <= r :
#   print(l,r)
  if l == r :
    mid = S[l]
    break
  elif S[l] == S[r] : 
    res += S[l]
    l += 1
    r -= 1
  else :
    if S[l+1] == S[r] : l += 1
    elif S[r-1] == S[l] : r -= 1
    elif l > N-r :
        # print(l,N-r,r)
        r -= 1
    else : l += 1
ans = res + mid + res[::-1]
# print(res,mid,ans)
if len(ans) >= N//2 : print(ans)
else : print ("IMPOSSIBLE")