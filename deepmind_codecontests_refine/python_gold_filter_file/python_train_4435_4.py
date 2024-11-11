n,h=map(int, input().split())
i=1
b=[]
while i<n:
    b.append(str(h*(i/n)**(1/2)))
    i+=1
print(" ".join(b))
