s=input().lower()
c=s.count('vk')
s1=s.split('vk')
c+=sum('vv' in i or 'kk' in i for i in s1)>0
print(c)