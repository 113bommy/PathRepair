text=input()
string=input()


#common_length[i]は、探索列がstring[i]で探索を終了したときに、
# string[i-common_lneght[i] + 1] 〜string[i]で構成される文字列が、探索価値を持つことを示す



len_string=len(string)
common_length=[0]*len_string
tmp=0
tmp_tmp=0
for i in range(1,len_string):
    if(string[i]==string[tmp]):
        tmp_tmp=tmp
        while(string[i]==string[tmp_tmp] and tmp_tmp >0):
            tmp_tmp=common_length[max([tmp_tmp-1,0])]
        common_length[i-1]=tmp_tmp
        tmp+=1
    else:
        common_length[i-1]=tmp
        while(string[i]!=string[tmp] and tmp>0):
            tmp=common_length[max([tmp-1,0])]
        if(string[i]==string[tmp]):
            tmp+=1

if(string[-1]==string[tmp-1]):
    common_length[-1]=tmp
common_length[0]=0


tmp=0

for i in range(len(text)):
    if(text[i]!=string[tmp]):
        while(text[i]!=string[tmp] and tmp>0):
            tmp=common_length[max([tmp-1,0])]
        if(text[i]==string[tmp]):
            tmp+=1
    else:
        tmp+=1
        if(tmp==len_string):
            print(i-tmp+1)
            tmp=common_length[-1]
