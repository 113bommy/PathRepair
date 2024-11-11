x, y = map(int, input().split())
n=0
while(2**n<=y//x):
    n+=1
print(n)