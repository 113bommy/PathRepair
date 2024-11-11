k = int(input())
if (k < 10):
    print(k)
    quit()
c=0
n=k
a = k
while (n > 0):
    c+=1
    sub = 10 ** c - 10 ** (c-1)
    a-=sub*c
    n = a / (c+1) + (10 ** c - 1)
    if (n+1 <= 10 ** (c+1)):
        if (int(n) == n):
            print(int(n%(10)))
            exit()
        else:
            print(str(int(n)+1)[round((n-int(n))*(c+1))-1])
            exit()
