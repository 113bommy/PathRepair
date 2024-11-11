w=input()
for i in range(len(w)):
    if w.count(w[i])%2!=0:
        print('No')
        exit()
print('Yes')