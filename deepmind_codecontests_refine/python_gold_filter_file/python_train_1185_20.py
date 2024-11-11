a,b,c,d = map(int, input().split())
probablity = a/b
a1 = a/b
a2 = c/d
for i in range(1, 10000):
    probablity = probablity+((1-a1)**i)*((1-a2)**i)*a1 
print(probablity)
