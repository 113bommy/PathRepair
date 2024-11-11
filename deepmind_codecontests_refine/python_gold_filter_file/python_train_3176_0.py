n , t = map(int , input().split())
num =( 10**(n-1))
a = 10**n
while (True and num <a ):
    if (num%t ==0):
        print(num)
        exit()
    num+=1
print(-1)


