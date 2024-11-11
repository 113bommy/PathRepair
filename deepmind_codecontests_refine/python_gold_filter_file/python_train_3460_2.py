import sys
 
t = input()
for i in range(int(t)):
    ar = []
    ar = map(int,input().split())
    ar = list(ar)
    print(ar[1], end = " ")
    print(ar[2] ,end = " ")
    print(ar[2])
    sys.stdout.flush()