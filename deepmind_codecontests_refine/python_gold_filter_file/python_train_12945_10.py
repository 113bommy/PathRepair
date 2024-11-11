s = input()
k = (sorted(s , reverse = True)) + [0]
i = 0
print(k[0],end="")
while k[i] == k[i+1] :
    print(k[i] ,end = "")
    i += 1