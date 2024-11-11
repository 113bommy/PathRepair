a,b=map(int,input().split())
ans = a+b if (b%a==0) else b-a
print(ans)
