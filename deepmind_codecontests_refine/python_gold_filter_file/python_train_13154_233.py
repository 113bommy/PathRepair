l = input()
counter =0
for i in range (len(l)):
    if l[i] not in l[i+1:]:
        counter+=1
if (counter % 2 == 0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")

