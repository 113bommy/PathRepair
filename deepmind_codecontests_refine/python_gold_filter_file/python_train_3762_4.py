a=int(input())
b=sorted(list(map(int,input().split())))
print(sum((b[i]+b[-(1+i)])*(b[i]+b[-(1+i)]) for i in range((a//2))))