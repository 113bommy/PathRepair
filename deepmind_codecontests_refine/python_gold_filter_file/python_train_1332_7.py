s = input()

i = 0
lst = [""]
for j in range(1,len(s)+1):
    if lst[-1] != s[i:j]:
        lst.append(s[i:j])
        i = j

print(len(lst)-1)