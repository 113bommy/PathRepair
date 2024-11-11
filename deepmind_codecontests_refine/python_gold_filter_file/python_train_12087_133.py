n = int(input())
text="EASY"
l = list(map(int,input().split()))
for i in l:
    if i==1:
        text="HARD"
        break
print(text)