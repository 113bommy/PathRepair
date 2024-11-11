#-------------Program--------------
#----Kuzlyaev-Nikita-Codeforces----
#-------------Training-------------
#----------------------------------

da,db=map(int,input().split())
if db-da==1:
    print(str(da)+"9",str(db)+"0")
elif da==9 and db==1:print(9,10)
elif da==db:print(str(da)+"0",str(db)+"1")
else:
    print(-1)