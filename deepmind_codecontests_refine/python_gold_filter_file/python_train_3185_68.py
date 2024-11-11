a,b = map(int, input().split())
c = 0
while not a>b:
    a*=3
    b*=2
    c+=1
print(c)