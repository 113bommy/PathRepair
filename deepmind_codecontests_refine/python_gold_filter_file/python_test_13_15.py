t = int(input())
for i in range(t):
    ch = input()
    a = ch.count('A')
    b = ch.count('B')
    c = ch.count('C')
    if b == a + c :
        print("YES")
    else:
        print("NO")