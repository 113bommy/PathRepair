n=int(input())
S=input()
a = [len(x)+1 for x in S.split('1')]
if n==0 :
    k=0
    for x in a :
        k+=int((x)/2*(x-1))
    print(k)
else :
    k=0
    for i in range(len(a)-n) :
        k+=a[i]*a[i+n]
    print(k)
