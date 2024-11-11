a, b = map(int, input().split())
n = 0
while(a<=b):
    n+=1
    a = a*3
    b = b*2
print(n)