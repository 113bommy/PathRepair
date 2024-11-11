_,s=open(0);a=[s.count('.')]
for i in s:a+=a[-1]+(i<'.'or-1),
print(min(a))