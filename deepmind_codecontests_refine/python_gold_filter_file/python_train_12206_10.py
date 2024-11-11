a=int(input())
mas = list(map(int, input().split(' ')))
b=0
suma=0
k=0
kol=[]
for i in range(a):
    suma+=mas[i]
suma/=a
for i in range(a):
    if mas[i]==suma:
        kol.append(i)
        k+=1
print(k)
if k!=0:
    for i in range(len(kol)):
        print(kol[i]+1, end=' ')