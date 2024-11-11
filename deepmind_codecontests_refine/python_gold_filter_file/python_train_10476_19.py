inp = input()
count = 0
for i in range(0,len(inp)-1):
    if inp[i]=='Q':
        for j in range(i+1,len(inp)):
            if inp[j]=='A':
                count+=inp[j+1::1].count('Q')
print(count)