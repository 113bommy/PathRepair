import sys
n = input()
n = '00' + n
for i in range(len(n)):
    for j in range(i+1, len(n)):
        for k in range(j+1, len(n)):
            if int(n[i] + n[j] + n[k]) %8 == 0:
                print("YES")
                print(int(n[i] + n[j] + n[k]))
                sys.exit()
print("NO")