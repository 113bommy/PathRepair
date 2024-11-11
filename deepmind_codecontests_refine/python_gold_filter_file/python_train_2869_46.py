i = 1
m = int(input())
while i <= m:
    n = input()
    if len(n) <= 10 :
        print (n)
    else:
        print(n[0],len(n)-2,n[-1],sep="")
    i+=1
