a,b=map(int,input().split())
print(0 if a==2 or b==2 else max(1,a-2)*max(1,b-2))