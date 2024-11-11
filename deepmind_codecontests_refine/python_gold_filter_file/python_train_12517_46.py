str = input()

doesOutput = False
for c in str:
    if(c in "HQ9"):
        doesOutput = True
        break

if(doesOutput):
    print("YES")
else:
    print("NO")
