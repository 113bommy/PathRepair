t = int(input())
for i in range(t):
    s = input()
    if(len(s) <= 10):
        print(s)
    else:
        print(s[0]+str(len(s)-2)+s[-1])