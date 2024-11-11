a=int(input());x="".join(input()+"\n"for i in" "*a);y=x.replace("OO","++",1);print("NO"*(x==y)or"YES\n"+y)
