from sys import stdin, stdout

#n = int(stdin.readline())
#a = int(stdin.readline())
#b = int(stdin.readline())
n = int(input())
a = int(input())
b= int(input())
x = 0
flg = False
if a % 2 == 0 and b % 2 == 0 and not n % 2 == 0:
    #stdout.write("NO\n")
    print("NO")
    exit()
elif n % a == 0:
    #stdout.write("YES\n")
    print("YES")
    #stdout.write(str(n // a) + " " + str(0))
    print(n//a, 0)
    exit()
elif n % b == 0:
    #stdout.write("YES\n")
    print("YES")
    #stdout.write(str(0) + " " + str(n // b))
    print(0, n//b)
    exit()
elif a == b and not n % b ==0:
    #stdout.write("NO\n")
    print("NO")
else:
    l = max(a, b)
    r = min(a, b)
    while l < n:
        if (n - l) % r == 0:
            print('YES')
            fig = True
            if a < b:
                #stdout.write(str((n-l)//a)+" "+ str(l//b))
                print((n - l) // a, l // b)
                exit()
            else:
                #stdout.write(str(l//a) + " " + str((n-l)//b))
                print(l // a, (n - l) // b)
                exit()

            break
        l = l + max(a, b)
    if not flg:
        #stdout.write("NO\n")
        print("NO")
