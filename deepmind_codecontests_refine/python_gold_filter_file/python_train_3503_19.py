n = int(input())
k = int(input())
a = int(input())
b = int(input())
s = 0
if k==1:
    print((n-1)*a)
else:
    if n==1:
        print(0)
    else:
        while(n!=1):
            if n<k:
                s+=(n-1)*a
                break
            else:
                x = n - (n//k)*k
                s+=x*a
                n -=x
                if (n-n//k)*a<b:
                    s+=(n-n//k)*a
                    n = n//k
                else:
                    s += b
                    n = n // k

        print(s)
