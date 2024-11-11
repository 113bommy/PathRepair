n = int(input())


for _ in range(n):
    s = input()
    if len(s) < 11 :
        print(s)
    else:
        print(s[0]+str(len(s)-2)+s[-1])
