input()
inputString = input()
ans = 0
for i in range(len(inputString) - 1, -1, -1):
    ans += 1
    #print(ans)
    if i % 2 == 0:
        continue
    if(inputString[: (i + 1) // 2] == inputString[(i + 1) // 2 : i + 1]):
        #print(inputString[: (i + 1) // 2] + " " + inputString[(i + 1) // 2 : i + 1])
        ans += i // 2 + 1
        break

print(ans)
exit()

