in_table=input()
in_hand=list(input().split())
flag=0
for ele in in_hand:
    if (in_table[0]==ele[0] or in_table[1]==ele[1]):
        flag=1
if flag==1:
    print("YES")
else:
    print("NO")
