t = int(input())
for _ in range(t):
    n, c = input().split()
    n= int(n)
    s = input()
    if all(x==c  for x in s):
        print(0)
    else:
        b = False
        for i in range(2, n+1):
            if all(s[q*i-1] == c for q in range(1, 1+ n//i)):
                b =True
                break
        if b:
            print(1)
            print(i)
        else:
            print(2)
            print(n-1, n)
        
    
        