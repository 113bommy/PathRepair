from math import ceil
h1,a1,c1=map(int,input().split())
h2,a2=map(int,input().split())
for i in range(100000):
    if(ceil((h1+i*(c1-a2))/(a2))>=ceil(h2/a1)):
        print(i+int(ceil(h2/a1)))
        for j in  range(i):
            print("HEAL")
        for j in range(int(ceil(h2/a1))):
            print("STRIKE")
        break



