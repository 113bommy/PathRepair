str = input()
count_lower = 0
count_upper = 0
for i in str:
        if i >= 'a' and i <= 'z':
                count_lower = count_lower + 1
        else:
                count_upper = count_upper + 1 
if count_lower >= count_upper:
        print(str.lower())
else:
        print(str.upper())

