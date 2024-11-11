r,g,b=map(int,input().split())
print("NO" if (g*10+b)%4 else "YES")