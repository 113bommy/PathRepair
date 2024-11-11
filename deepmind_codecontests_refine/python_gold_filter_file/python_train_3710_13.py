h1,a1,c1=[int(x) for x in input().split()]
h2,a2=[int(x) for x in input().split()]
x=h2//a1+bool(h2%a1)
t=max(0,((x-1)*a2-h1)//(c1-a2)+1)
print(t+x)
for i in range(t):
    print("HEAL")
for i in range(x):
    print("STRIKE")
