x = int(input())
y = list(map(int,input().split()))
z = sorted(y,reverse = True)

for i in y:
    a = ''.join(str(z.index(i)+1))
    print(a,end=" ")

