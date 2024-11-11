a = int(input())
for i in range(a):
    s = input()
    l = len(s)
    if l%2==0:
        if s[0:(l//2)] == s[(l//2):l]:
            print("yes")
        else:
            print("no")
    else:
        print("no")
