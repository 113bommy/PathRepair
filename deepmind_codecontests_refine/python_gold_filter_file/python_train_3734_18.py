w=input()
for alphabet in w:
    if w.count(alphabet)%2!=0:
        print("No")
        exit()
print("Yes")