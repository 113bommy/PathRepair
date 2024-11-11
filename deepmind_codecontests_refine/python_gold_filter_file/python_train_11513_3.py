import random
n , k = input().split()
n , k = int(n) , int(k)
st = ""
i = 0
while len(st) < n:
    value = chr(random.randint(97, 122))
    if k >= 1:
        if not value in st:
            st+=value
            k-=1
    if(k<1):
        if not value == st[len(st)-1]:
            if value in st:
                if st.isalpha():
                    st+=value

print(st)



