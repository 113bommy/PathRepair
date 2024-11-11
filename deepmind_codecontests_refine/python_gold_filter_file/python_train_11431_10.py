a,b=map(int, input().split())


l = [i for i in range(b-a+1,b+a)]

print(*l)