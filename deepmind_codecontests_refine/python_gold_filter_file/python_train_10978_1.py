M = 1000000007
a,b = map(int, input().split(' '))
res = b*(b-1)//2*(a+b*a*(a+1)//2)%M
print(res)
