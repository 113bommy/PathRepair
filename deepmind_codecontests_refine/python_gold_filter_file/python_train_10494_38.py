n,a,b,c,d = map(int, input().split())
a -= 1
b -= 1
s = input()
ans = "No"
snk = s[a:c].count("##")
fnk = s[b:d].count("##")
if snk == 0 and fnk == 0:
  if c > d:
    if s[b-1:d+1].count("...") >= 1:
      ans = "Yes"
  else:
    ans = "Yes"
    
print(ans)