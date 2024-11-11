number = int(input())
string = input()

count_z=0
count_e=0
count_r=0
count_o=0
count_n=0
 
for i in string:
    if i=='z':
        count_z+=1
    if i=='e':
        count_e+=1
    if i=='r':
        count_r+=1
    if i=='o':
        count_o+=1
    if i=='n':
        count_n+=1
min_one = min(count_o,count_n,count_e)
min_zero = min(count_z,count_e-min_one,count_r,count_o-min_one)
chislo = int(min_one+min_zero)
print('{} {}'.format('1 '*min_one,'0 '*min_zero))