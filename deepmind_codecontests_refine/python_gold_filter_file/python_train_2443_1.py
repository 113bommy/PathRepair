n = int(input())
if n == 4:
    print ("YES\n1 3 2 4")
elif [i for i in range(2,n) if n%i==0]:
    print("NO")
else:
    print("YES\n1 %s"%(" ".join(str((pow(x+1,n-2,n)*(x+2))%n or n) for x in range(n-1))))