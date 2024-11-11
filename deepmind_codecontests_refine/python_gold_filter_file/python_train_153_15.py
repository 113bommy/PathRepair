traffic = 0
users = 0

import sys
input_main = sys.stdin.read()
input_l = input_main.splitlines()
#print(input_main)
for st in input_l:
    if st[0] == '+':
        users+=1
    elif st[0] == '-':
        users-=1
    else:
        l = len(st[st.find(':')+1:])
        traffic += l * users
       
print(traffic)
