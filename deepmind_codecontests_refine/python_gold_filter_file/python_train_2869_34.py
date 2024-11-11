n = int(input())
for x in range(n):
    a = input()
    if len(a)<=10:
        print(a)
    else:
        print(a[0]+str(len(a)-2)+a[-1])