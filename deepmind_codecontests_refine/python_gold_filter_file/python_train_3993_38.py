str_in = input()
num = [int(n) for n in str_in.split()]
ml = num[0]/num[2] if num[0]/num[2] - (int)(num[0]/num[2]) == 0 else (int)(num[0]/num[2]) + 1
nl = num[1]/num[2] if num[1]/num[2] - (int)(num[1]/num[2]) == 0 else (int)(num[1]/num[2]) + 1
print((int)(ml * nl))