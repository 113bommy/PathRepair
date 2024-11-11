import sys

def main():
    s=sys.stdin.readline().rstrip()
    h,m=s.split(':')
    
    if h[1] in ('0','1','2','3','4','5'):
        midminute=h[1]+h[0]
        if m<=midminute:
            hnext,mnext=h,midminute
        elif h=='05':
            hnext,mnext='10','01'
        elif h=='15':
            hnext,mnext='20','02'
        elif h=='23':
            hnext,mnext='00','00'
        else:
            hnext='{:02d}'.format(int(h)+1)
            mnext=hnext[1]+hnext[0]
    elif h[0]=='0':
        hnext,mnext='10','01'
    elif h[0]=='1':
        hnext,mnext='20','02'
        
    ih=int(h)
    im=int(m)
    ihnext=int(hnext)
    imnext=int(mnext)
    if ihnext==0 and ih>0: ihnext=24
    result=(ihnext-ih)*60+(imnext-im)
    
    sys.stdout.write(str(result)+'\n')
    
main()

