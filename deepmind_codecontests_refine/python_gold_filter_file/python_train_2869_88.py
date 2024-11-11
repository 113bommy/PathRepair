t = int(input())
for i in range(0,t):
    s = input()
    if len(s) <= 10:
        print(s)
    else:
        print(s[0:1]+str(len(s)-2)+s[-1::])