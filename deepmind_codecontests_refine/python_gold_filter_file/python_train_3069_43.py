CountB,CountW=0,0
dict={}
dict['q']=9
dict['r']=5
dict['b']=3
dict['k']=0
dict['p']=1
dict['n']=3
for i in range(8):
    s=str(input())
    for j in s:
        if j!='.' and j.upper()==j:
            CountW+=dict[j.lower()]
        elif j!='.' and j.lower()==j:
            CountB+=dict[j.lower()]
if CountB==CountW:
    print("Draw")
elif CountB>CountW:
    print("Black")
else:
    print("White")