N , V = map(int, input().split())
chars = [int(x) for x in input().split()]
count = 0
chars.sort()
yo = 0
for i in range(0, len(chars)-1):
        yo = yo + chars[i]
if yo <= V:
    print ("YES")
else:
    print ("NO")