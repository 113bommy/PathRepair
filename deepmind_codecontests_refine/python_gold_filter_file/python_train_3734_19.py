w=input()
for ch in w:
  if w.count(ch)%2!=0:
    print("No")
    exit()
print("Yes")