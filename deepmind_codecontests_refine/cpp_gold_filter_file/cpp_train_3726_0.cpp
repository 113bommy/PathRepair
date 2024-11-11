#include <stdio.h>
#include <math.h>

int n,x[55],y[55];
double gx,gy;

int main()
{
  scanf ("%d",&n);
  for (int i=0;i<n;i++) scanf ("%d %d",&x[i],&y[i]), gx +=x[i], gy += y[i];
  gx /= n, gy /= n;
  
double ans;
  for (double p=1;p>=1e-8;p*=0.999){
int idx = -1; double dist = -1;
    for (int i=0;i<n;i++){
		double d = hypot(x[i]-gx,y[i]-gy);
      if (dist < d) dist = d, idx = i;
    }
    gx += (x[idx] - gx) * p;
    gy += (y[idx] - gy) * p;
    ans = dist;
  }
  
  printf ("%.12lf\n",ans);
return 0;
}
