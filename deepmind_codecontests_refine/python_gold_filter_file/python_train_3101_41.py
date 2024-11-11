a,b,c = map(int,input().split())
ans = "No"

if c-a-b>0 and 4*a*b<pow(c-b-a,2):ans = "Yes"

print(ans)