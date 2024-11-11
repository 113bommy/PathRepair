n , a , b , c , d = map(int,input().split())
s = input()
if s[a:c+1].count("##") != 0 or s[b:d+1].count("##") != 0:
    print("No")
    exit()
if c > d:
    if s[b-2:d+1].count("...") == 0:
        print("No")
        exit()
print("Yes")