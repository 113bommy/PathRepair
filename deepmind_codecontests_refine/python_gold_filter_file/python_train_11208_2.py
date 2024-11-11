n=int(input())
st=input()
count=0
while 'xxx' in st:  
    st=st.replace('xxx','xx',1)
    count+=1
print(count)